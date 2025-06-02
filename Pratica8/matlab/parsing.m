filename = 'C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt';

fid = fopen(filename, 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

while ~feof(fid)
    line = fgetl(fid);
    if ischar(line)
        tokens = strsplit(line, ','); % divide a linha usando vírgulas
        for i = 1:length(tokens)
            disp(tokens{i}); % exibe cada token separado
        end
    end
end

fclose(fid);
