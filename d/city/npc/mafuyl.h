int do_rideyl()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("say ��������"+ob->query("name")+
                "���"+RANK_D->query_rude(ob)+"��͵��\n");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"������"NOR;
                        break;
                case 2:
                        hname=RED"�����"NOR;
                        break;
                default:
                        hname=HIY"������"NOR;
                        break;
        }
        message_vision(
"������ָ�$Nǣ��һƥ"+hname+"��$N����Ծ��������������������·������һ��
���: �����ޡ�\n"NOR , ob );
        message_vision("\nֻ��$N������һ�У�"+hname+"�����͵��ȥ��\n",ob);
        if (ob->query("jing") > 1000) {
            ob->receive_damage("jing", 100);
        }
        if (ob->query("jing") > 200) {
            ob->receive_damage("jing", 50);
        }
        ob->receive_damage("jing", 30);
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳��������ɽ���µ�������\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��塣\n",ob);
        message_vision("\n$N�е������ˣ��Ǹ���Ϣһ���ˡ�\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
