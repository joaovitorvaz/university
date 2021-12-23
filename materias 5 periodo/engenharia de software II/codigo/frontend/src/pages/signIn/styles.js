import styled from 'styled-components';
import background from '../../assets/signIn/background.png';
import {ContainerImage} from "../../components/global";
import {Link} from 'react-router-dom';


export const Redirect = styled(Link)`
  width: 100%;
  display: flex;
  justify-content: center;
`;

export const ContainerSignIn = styled(ContainerImage)`
  min-height: 100vh;
  justify-content: center;
  align-items: center;
  background: url(${background}) fixed;
  background-size: cover;
`;

export const Section = styled.div`
  width: 45%;
  height: 50vh;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  /* background-color: rgba(36, 0, 70, 0.5); */
  background-color: ${({ theme }) => theme.colors.cardBackground};
  border: 1px solid #6B33FF;
  border-radius: 15px;
  backdrop-filter: blur(20px);
`;

export const SignUp = styled.div`
  width: 80%;
  display: flex;
  justify-content: flex-end;

  p{
    padding: 5px;
  }

  b{
    color: ${({ theme }) => theme.colors.secondary};
    font-weight: normal;

    :hover {
      color: ${({ theme }) => theme.colors.third};
    }
  }
`;

export const ButtonSection = styled.div`
  width: 100%;
  display: flex;
  justify-content: center;
`;