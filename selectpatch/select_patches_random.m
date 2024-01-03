function [patches, patchNum_MMS] = select_patches_random(ourfile, sampleNum, leftdata, rightdata,featdim, patchsize)  
    patchNum_MMS = 1008

    ind = [];
    for x=randperm(150,28)
        for y=randperm(100,18)
            if x+patchsize-1 > 150 && y+patchsize-1 > 100
                ind = [ind,getindex(x:150,y:100,patchsize)];
                ind = [ind,getindex(1:x+patchsize-150-1,y:100,patchsize)];
                ind = [ind,getindex(1:x+patchsize-150-1,1:y+patchsize-100-1,patchsize)];
                ind = [ind,getindex(x:150,1:y+patchsize-100-1,patchsize)];
            elseif x+patchsize-1 > 150 && y+patchsize-1 <= 100
                ind = [ind,getindex(x:150,y:y+patchsize-1,patchsize)]; 
                ind = [ind,getindex(1:x+patchsize-150-1,y:y+patchsize-1,patchsize)];
            elseif x+patchsize-1 <= 150 && y+patchsize-1 > 100
                ind = [ind,getindex(x:x+patchsize-1, y:100,patchsize)];
                ind = [ind,getindex(x:x+patchsize-1, 1:y+patchsize-100-1,patchsize)];
            else
                ind = [ind,getindex(x:x+patchsize-1, y:y+patchsize-1,patchsize)];
            end
        end
    end

    ind = [ind, ind+15000];


    leftdata = reshape(leftdata, 15000, featdim, sampleNum);
    rightdata = reshape(rightdata, 15000, featdim, sampleNum);
    allMMS = cat(1,leftdata,rightdata);
    patches = allMMS(ind,:,:);
    patches = reshape(patches, patchsize^2,patchNum_MMS,featdim,sampleNum);
    patches = cat(1, patches(:,:,1,:), patches(:,:,2,:),patches(:,:,3,:),patches(:,:,4,:));
    patches = reshape(patches, featdim*patchsize^2, patchNum_MMS* sampleNum);
    save(ourfile, 'patches', '-ASCII');
end

function [ind] = getindex(x, y, patchsize)
    ind = [];
    for i = y
        for j = x
            ind = [ind,(i-1)*150+j];
        end
    end

end
