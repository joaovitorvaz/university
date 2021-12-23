/* eslint-disable jsx-a11y/anchor-is-valid */
import React from 'react';
import {InitialSection, ContainerSupport, Section, SocialSection, SocialLine, Icon} from "./styles";
import instagram from '../../assets/support/instagram.svg'; // Colocar icones corretos e imagem de fundo correta
import github from '../../assets/support/github.svg'; // Colocar icones corretos e imagem de fundo correta
import twitter from '../../assets/support/twitter.svg'; // Colocar icones corretos e imagem de fundo correta
import email from '../../assets/support/email.svg'; // Colocar icones corretos e imagem de fundo correta
import facebook from '../../assets/support/facebook.svg'; // Colocar icones corretos e imagem de fundo correta
import whatsapp from '../../assets/support/whatsapp.svg'; // Colocar icones corretos e imagem de fundo correta

export default function Support() {

  return (
    <ContainerSupport>
      <InitialSection>
        <h1>SUPORTE LOKA GAMES</h1>
      </InitialSection>
      <Section>
        <p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.</p>
        <SocialSection>
          <SocialLine><Icon src={instagram} /><p>@LokaGames</p></SocialLine>
          <SocialLine><Icon src={email} /><p>suporte@lokagames.com</p></SocialLine>
          <SocialLine><Icon src={github} /><p>lokagames</p></SocialLine>
          <SocialLine><Icon src={facebook} /><p>lokagames</p></SocialLine>
          <SocialLine><Icon src={twitter} /><p>@lokagames</p></SocialLine>
          <SocialLine><Icon src={whatsapp} /><p>4002-8922</p></SocialLine>
        </SocialSection>
      </Section>
    </ContainerSupport>
  );
}