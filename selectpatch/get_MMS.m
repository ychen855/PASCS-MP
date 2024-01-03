function [size,res] = get_MMS(folder)

    files = dir(fullfile(folder, '*.m'));
    size = length(files);
    % res = 0;
    % for i=1:size
    %     disp(files(i))
    % end
    res = zeros(15000,4, size);
    for i = 1:size
        file = files(i);
       [~,~,feature] = read_mfile([file.folder,'/',file.name]);
       res(:,:,i) = feature.Vertex_Jfeature(:,1:4);
    end

    res = reshape(res,150,100,4,length(files));
end