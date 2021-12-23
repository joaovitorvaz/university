/* eslint-disable jsx-a11y/anchor-is-valid */
import React, {useState} from 'react';
import {Redirect, ContainerSignUp, Section, Form, ButtonSection} from "./styles";
import Input from "../../components/input";
import Button from "../../components/button";

export default function SignIn() {

  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [confirmPassword, setConfirmPassword] = useState("");
  const [cpf, setCpf] = useState("");
  const [birth, setBirth] = useState("");
  const [contact, setContact] = useState("");

  return (
    <ContainerSignUp>
      <Section>
        <Input onChange={e => setName(e.target.value)} value={name} labelName="Nome Completo" size="100%" />
        <Form>
          <Input onChange={e => setEmail(e.target.value)} value={email} labelName="E-mail" size="100%" />
          <Input onChange={e => setPassword(e.target.value)} value={password} labelName="Senha" password={true} size="100%" />
          <Input onChange={e => setConfirmPassword(e.target.value)} value={confirmPassword} labelName="Confirmar senha" password={true} size="100%" />
          <Input onChange={e => setCpf(e.target.value)} value={cpf} labelName="CPF" size="100%" />
          <Input onChange={e => setBirth(e.target.value)} value={birth} labelName="Data de nascimento" size="100%" />
          <Input onChange={e => setContact(e.target.value)} value={contact} labelName="Telefone" size="100%" />
        </Form>
        <ButtonSection>
          <Redirect to="/signIn"><Button buttonName="Voltar" size="90%"/></Redirect>
          <Redirect to="/"><Button buttonName="Cadastrar" size="90%"/></Redirect>
        </ButtonSection>
      </Section>
    </ContainerSignUp>
  );
}