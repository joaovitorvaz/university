/* eslint-disable jsx-a11y/anchor-is-valid */
import React, {useState} from 'react';
import {Redirect, ContainerProfile, Section, IconSection, Icon, Form, ButtonSection} from "./styles";
import Input from "../../components/input";
import Button from "../../components/button";

import profile from '../../assets/profile/profile.png';

export default function Profile() {

  const [name, setName] = useState("Cristiano Ronaldo dos Santos Aveiro"); 
  const [email, setEmail] = useState("cr7@gmail.com"); 
  const [cpf, setCpf] = useState("777.777.777-77"); 
  const [birth, setBirth] = useState("05/02/1985"); 
  const [contact, setContact] = useState("(77) 7777-7777"); 

  const [readOnly, setReadOnly] = useState(true); 

  const edition = () => {
    setReadOnly(!readOnly);
  } 

  return (
    <ContainerProfile>
      <Section>
        <IconSection>
          <Icon src={profile} />
          <p>PERFIL</p>
        </IconSection>
        <Input readOnly={readOnly} value={name} onChange={e => setName(e.target.value)} labelName="Nome Completo" size="100%" />
        <Form>
          <Input readOnly={readOnly} value={email} onChange={e => setEmail(e.target.value)} labelName="E-mail" size="100%" />
          <Input readOnly={readOnly} value={cpf} onChange={e => setCpf(e.target.value)} labelName="CPF" size="100%" />
          <Input readOnly={readOnly} value={birth} onChange={e => setBirth(e.target.value)} labelName="Data de nascimento" size="100%" />
          <Input readOnly={readOnly} value={contact} onChange={e => setContact(e.target.value)} labelName="Telefone" size="100%" />
        </Form>
        <ButtonSection>
          <Redirect to={readOnly? "/signIn" : "/"}><Button buttonName={readOnly? "Sair" : "Voltar"} size="90%"/></Redirect>
          <Button onClick={edition} buttonName={readOnly? "Editar" : "Salvar"} size="45%"/>
        </ButtonSection>
      </Section>
    </ContainerProfile>
  );
}