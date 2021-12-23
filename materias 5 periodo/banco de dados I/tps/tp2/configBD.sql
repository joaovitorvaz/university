CREATE TABLE Cupom (
    Codigo   NUMERIC(2)   NOT NULL,
    Desconto NUMERIC(3) NOT NULL,

    CONSTRAINT pk_cupom PRIMARY KEY (Codigo)
);

CREATE TABLE Pessoa (
    Cpf  VARCHAR(14) NOT NULL,
    Nome VARCHAR(50) NOT NULL,

    CONSTRAINT pk_pesoa PRIMARY KEY (Cpf)
    
);

CREATE TABLE Produtor(
    ChaveSubstituta NUMERIC(2) NOT NULL,

    CONSTRAINT pk_produtor PRIMARY KEY (ChaveSubstituta)
);

CREATE TABLE Empresa (
    Cnpj VARCHAR(18) NOT NULL,
    Nome VARCHAR(30) NOT NULL,

    CONSTRAINT pk_empresa PRIMARY KEY (Cnpj)
);

CREATE TABLE Genero (
    Codigo Numeric(2)  NOT NULL,
    Nome   VARCHAR(30) NOT NULL,

    CONSTRAINT pk_genero PRIMARY KEY (Codigo)
);

CREATE TABLE Usuario (
    Cpf   VARCHAR(14)  NOT NULL,
    Login VARCHAR(14) NOT NULL,
    Senha VARCHAR(14)  NOT NULL,
    Sexo  CHAR(1)      NOT NULL,

    CONSTRAINT pk_usuario PRIMARY KEY (Cpf),
    CONSTRAINT ck_sexo CHECK (Sexo='M' or Sexo='F')

);

CREATE TABLE Desenvolvedor (
    Cpf             VARCHAR(14) NOT NULL,
    ChaveSubstituta NUMERIC(2)  NULL,

    CONSTRAINT pk_desenvolvedor PRIMARY KEY (Cpf)
);

CREATE TABLE Estudio (
    Cnpj            VARCHAR(18) NOT NULL,
    ChaveSubstituta NUMERIC(2)  NULL,

    CONSTRAINT pk_estudio PRIMARY KEY (Cnpj)
);

CREATE TABLE Endereco (
    Numero NUMERIC(4)  NOT NULL,
    Rua    VARCHAR(18) NOT NULL,
    Bairro VARCHAR(18) NOT NULL,
    Cidade VARCHAR(18) NOT NULL,
    Pais   VARCHAR(18) NOT NULL,
    Cnpj   VARCHAR(18) NOT NULL,

    CONSTRAINT pk_endereco PRIMARY KEY (Numero, Rua, Bairro, Cidade, Pais, Cnpj)
);

CREATE TABLE Distribuidora (
    Cnpj VARCHAR(18) NOT NULL,

    CONSTRAINT pk_distribuidora PRIMARY KEY (Cnpj)
);

CREATE TABLE Jogo (
    Codigo        NUMERIC(2)   NOT NULL,
    Nome          VARCHAR(30)  NOT NULL,
    Classificacao NUMERIC(2)   NOT NULL,
    Valor         NUMERIC(5,2) NOT NULL,
    Produtor      NUMERIC(2)   NOT NULL,
    Distribuidora VARCHAR(18)  NOT NULL,

    CONSTRAINT pk_jogo PRIMARY KEY (Codigo)
);

CREATE TABLE Exemplar (
   Numero     NUMERIC(2) NOT NULL,
   CodigoJogo NUMERIC(2) NOT NULL,

   CONSTRAINT pk_exemplar PRIMARY KEY (Numero, CodigoJogo)
);

CREATE TABLE Aluguel (
    DataAluguel    DATE         NOT NULL,
    CpfUsuario     VARCHAR(14)  NOT NULL,
    CodigoCupom    NUMERIC(2)   NOT NULL,
    NumeroExemplar NUMERIC(2)   NOT NULL,
    CodigoJogo     NUMERIC(2)   NOT NULL,
    DataLimite     DATE         NOT NULL,
    Valor          NUMERIC(5,2) NOT NULL,

    CONSTRAINT pk_aluguel PRIMARY KEY (DataAluguel, CpfUsuario)
);

CREATE TABLE Fisico (
    CodigoJogo    NUMERIC(2) NOT NULL,
    Identificacao NUMERIC(2) NOT NULL,

    CONSTRAINT pk_fisico PRIMARY KEY (CodigoJogo)
);

CREATE TABLE Digital (
    CodigoJogo    NUMERIC(2)  NOT NULL,
    ChaveAtivacao VARCHAR(19) NOT NULL,

    CONSTRAINT pk_digital PRIMARY KEY (CodigoJogo)
);

CREATE TABLE RelacaoGenero (
    CodigoJogo   Numeric(2) NOT NULL,
    CodigoGenero Numeric(2) NOT NULL,

    CONSTRAINT pk_relacaoGenero PRIMARY KEY (CodigoJogo, CodigoGenero)
);

CREATE TABLE RelacaoCupom (
    CodigoCupom NUMERIC(2)  NOT NULL,
    CpfUsuario  VARCHAR(14) NOT NULL,

    CONSTRAINT pk_relacaoCupom PRIMARY KEY (CodigoCupom, CpfUsuario)
);

INSERT INTO Cupom
VALUES (01, 10);

INSERT INTO Pessoa
VALUES ('111.111.111-11', 'João Ferreira');
INSERT INTO Pessoa
VALUES ('578.847.812-04', 'Lara Elza Alana da Luz');

INSERT INTO Produtor
VALUES (01);
INSERT INTO Produtor
VALUES (02);

INSERT INTO Empresa
VALUES ('33.219.646/0001-13', 'Igor e Emanuel Distribuidora');
INSERT INTO Empresa
VALUES ('23.893.946/0001-20', 'Loka Games');

INSERT INTO Genero
VALUES (01, 'Ação');

INSERT INTO Usuario
VALUES ('111.111.111-11', 'admin', '12345', 'M');

INSERT INTO Desenvolvedor
VALUES ('578.847.812-04', 01);

INSERT INTO Estudio
VALUES ('23.893.946/0001-20', 02);

INSERT INTO Endereco
VALUES (5, 'Rua A', 'Cidade Nova', 'Aracaju', 'Brasil', '33.219.646/0001-13');
INSERT INTO Endereco
VALUES (6, 'Rua A', 'Cidade Nova', 'Aracaju', 'Brasil', '23.893.946/0001-20');

INSERT INTO Distribuidora
VALUES ('33.219.646/0001-13');

INSERT INTO Jogo
VALUES (01, 'Legends of Runeterra', 14, 14.99, 01, '33.219.646/0001-13');
INSERT INTO Jogo
VALUES (02, 'League of Legends', 14, 14.99, 02, '33.219.646/0001-13');

INSERT INTO Exemplar
VALUES (01, 01);
INSERT INTO Exemplar
VALUES (01, 02);

INSERT INTO Aluguel
VALUES (NOW(), '111.111.111-11', 01, 01, 01, NOW() + interval '365 days', 15.00);

INSERT INTO Fisico
VALUES (01, 01);

INSERT INTO Digital
VALUES (02, '1234-1234-1234-1234');

INSERT INTO RelacaoGenero
VALUES (01, 01);

INSERT INTO RelacaoCupom
VALUES (01, '111.111.111-11');

ALTER TABLE Usuario
ADD CONSTRAINT fk_usuario_pessoa FOREIGN KEY (Cpf) REFERENCES Pessoa (Cpf)
ON DELETE CASCADE;

ALTER TABLE Desenvolvedor
ADD CONSTRAINT fk_dev_pessoa FOREIGN KEY (Cpf) REFERENCES Pessoa (Cpf) 
ON DELETE CASCADE;

ALTER TABLE Desenvolvedor
ADD CONSTRAINT fk_dev_produtor FOREIGN KEY (ChaveSubstituta) REFERENCES Produtor (ChaveSubstituta) 
ON DELETE SET NULL;

ALTER TABLE Estudio
ADD CONSTRAINT fk_estudio_empresa FOREIGN KEY (Cnpj) REFERENCES Empresa (Cnpj) 
ON DELETE CASCADE;

ALTER TABLE Estudio
ADD CONSTRAINT fk_estudio_produtor FOREIGN KEY (ChaveSubstituta) REFERENCES Produtor (ChaveSubstituta) 
ON DELETE SET NULL;

ALTER TABLE Endereco
ADD CONSTRAINT fk_endereco_empresa FOREIGN KEY (Cnpj) REFERENCES Empresa (Cnpj) 
ON DELETE CASCADE;

ALTER TABLE Distribuidora
ADD CONSTRAINT fk_distribuidora_empresa FOREIGN KEY (Cnpj) REFERENCES Empresa (Cnpj) 
ON DELETE CASCADE;

ALTER TABLE Jogo
ADD CONSTRAINT fk_jogo_distribuidora FOREIGN KEY (Distribuidora) REFERENCES Distribuidora (Cnpj) 
ON DELETE RESTRICT;

ALTER TABLE Jogo
ADD CONSTRAINT fk_jogo_produtor FOREIGN KEY (Produtor) REFERENCES Produtor (ChaveSubstituta) 
ON DELETE RESTRICT;

ALTER TABLE Exemplar
ADD CONSTRAINT fk_exemplar_jogo FOREIGN KEY (CodigoJogo) REFERENCES Jogo (Codigo) 
ON DELETE CASCADE;

ALTER TABLE Aluguel
ADD CONSTRAINT fk_aluguel_usuario FOREIGN KEY (CpfUsuario) REFERENCES Usuario (Cpf) 
ON DELETE RESTRICT;

ALTER TABLE Aluguel
ADD CONSTRAINT fk_aluguel_cupom FOREIGN KEY (CodigoCupom) REFERENCES Cupom (Codigo) 
ON DELETE RESTRICT;

ALTER TABLE Fisico
ADD CONSTRAINT fk_fisico_jogo FOREIGN KEY (CodigoJogo) REFERENCES Jogo (Codigo) 
ON DELETE CASCADE;

ALTER TABLE Digital
ADD CONSTRAINT fk_digital_jogo FOREIGN KEY (CodigoJogo) REFERENCES Jogo (Codigo) 
ON DELETE CASCADE;

ALTER TABLE RelacaoGenero
ADD CONSTRAINT fk_relacaoGenero_jogo FOREIGN KEY (CodigoJogo) REFERENCES Jogo (Codigo) 
ON DELETE CASCADE;

ALTER TABLE RelacaoGenero
ADD CONSTRAINT fk_relacaoGenero_genero FOREIGN KEY (CodigoGenero) REFERENCES Genero (Codigo) 
ON DELETE CASCADE;

ALTER TABLE RelacaoCupom
ADD CONSTRAINT fk_relacaoCupom_cupom FOREIGN KEY (CodigoCupom) REFERENCES Cupom (Codigo) 
ON DELETE CASCADE;

ALTER TABLE RelacaoCupom
ADD CONSTRAINT fk_relacaoCupom_usuario FOREIGN KEY (CpfUsuario) REFERENCES Usuario (Cpf) 
ON DELETE CASCADE;