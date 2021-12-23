// /* eslint-disable jsx-a11y/anchor-is-valid */
import React, {useState} from 'react';
import { Link, useLocation } from 'react-router-dom';
import {SizeMe} from 'react-sizeme';
import {ContainerGamePage, GameData, ImageSection, InformationSection, GoBack, Image, GameName, Details, ButtonSection, Block, PopUp} from "./styles";
import Button from "../../components/button";
import {Loader} from "../../components/global";

export default function GamePage() {
    const [payment, setPayment] = useState(false);
    const [earn, setEarn] = useState(false);
    const [buttonStatus, setButtonStatus] = useState("Alugar agora"); 
    const [pageHeight, setPageHeight] = useState(0);
    
    let location = useLocation();
    let game = location.state;

    const sleep = (ms) => {
        return new Promise(resolve => setTimeout(resolve, ms));
    }

    const rent = async () => {
        setPayment(true);
        await sleep(3000);
        setPayment(false);
        setEarn(true);
        setButtonStatus("Adquirido");
    }
    
    return (
        <>
            <SizeMe monitorHeight>
                {({ size }) => (
                    <ContainerGamePage id="GamePageContainer">
                        <GoBack><Link to="/"><p>{'< Voltar'}</p></Link></GoBack>
                        <GameData>
                            <ImageSection>
                                <Image src={game.image} />
                            </ImageSection>
                            <InformationSection>
                                <GameName>{game.name}</GameName>
                                <p>{game.info}</p>
                                <Details>
                                    <p>Genêro: {game.genre}</p>
                                    <p>Classificação: {game.classification}</p>
                                    <p>Plataforma: {game.platform}</p>
                                    <p>Preço:<b>R${game.price}</b></p>
                                </Details>
                                <ButtonSection>
                                    <Button onClick={rent} buttonName={buttonStatus} size="50%" block={earn}/>
                                </ButtonSection>                    
                            </InformationSection>
                        </GameData>
                        {setPageHeight(size.height)}
                    </ContainerGamePage>
                )}
            </SizeMe>
            {payment && 
                <Block height={pageHeight.toString() + "px"}>
                    <PopUp>
                        <h3>Você está adquirindo {game.name}</h3>
                        <p>Aguarde enquanto processamos o pagamento</p>
                        <Loader />
                    </PopUp>
                </Block>
            }  
        </>
    );
}