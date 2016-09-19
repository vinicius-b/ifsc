
DROP TABLE IF EXISTS matricula;
DROP TABLE IF EXISTS curso;
DROP TABLE IF EXISTS curriculo;
DROP TABLE IF EXISTS disciplina;
DROP TABLE IF EXISTS aluno;
DROP TABLE IF EXISTS campus;
DROP DATABASE IF EXISTS bcd;
CREATE DATABASE IF NOT EXISTS bcd;
USE bcd;

CREATE TABLE IF NOT EXISTS campus (
	id unsigned tinyint auto_increment primary key,
	nome varchar(128) not null
)
CREATE TABLE IF NOT EXISTS aluno(
	id unsigned int auto_increment primary key,
	nome varchar(128) not null,
	documento char(11) unique not null,
	telefone unsigned bigint,
	email varchar(128)
)

CREATE TABLE IF NOT EXISTS disciplina(
    id unsigned smallint auto_increment primary key,
    codigo unsigned int unique not null,
    nome char(100) not null,
    CH unsigned tinyint not null,
    CHmin unisigned smallint not null
);
CREATE TABLE IF NOT EXISTS curriculo(
    id unsigned smallint auto_increment primary key,
    implantacao date not null,
    disciplina unsigned smallint not null,
    constraint fk_curriculo_disciplina_disciplina_id foreign key(disciplina) references disciplina(id)
);

CREATE TABLE IF NOT EXISTS curso(
   	id unsigned smallint auto_increment primary key,
   	numero unsigned smallint unique not null,
   	CHmin unsigned int not null,
   	CHmax unsigned int not null,
   	nome varchar(128) not null,
   	campus unsigned tinyint not null,
   	curriculo varchar(128),
   	constraint fk_curso_campus_campus_id foreign key(campus) references campus(id),
   	constraint fk_curso_curriculo_curriculo_id foreign key(curriculo) references curriculo(id)
);

CREATE TABLE IF NOT EXISTS matricula (
	id unsigned int auto_increment primary key,
    numero unsigned bigint unique not null,
    aluno unsigned int not null,
	curso unsigned smallint not null,
    constraint fk_matricula_aluno_aluno_id foreign key(aluno) references aluno(id),
    constraint fk_matricula_curso_curso_id foreign key(curso) references curso(id)
)

