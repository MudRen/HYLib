// mafu.c ���

inherit NPC;
#include <ansi.h>
int do_ride();

void create()
{
        set_name("���", ({ "ma fu","ma fu"}));
        set("age", 32);
        set("gender", "����");
        set("long","ѱ��������С�����������Ϳ��Թ͵���
        ������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�
        \n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 30);
        set("chat_chance",2);
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_rideyz", "rideyz");
	add_action("do_ridebj", "ridebj");
	add_action("do_rideht", "rideht");        
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "����ͷ������˵������λ�͹٣����뵽������һƥ����ɣ�\n");
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (ob->query("money_id") && ob->value() >= 100)
	{
	message_vision("����$N˵���ã���λ"+RANK_D->query_respect(who) +
		"���ھͳ�����? �Ǿ�����ɡ�\n", who);
		this_player()->set_temp("marks/horserent",1);
 	      	return 1;
	}
	else  
		message_vision("�����ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
	return 1;
}

int do_rideydx()
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
	ob->move("/d/huanghe/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�����������ء�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}


int do_rideyp()
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
	ob->move("/d/yanping/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳��������ƽ�ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}

int do_ridejl()
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
	ob->move("/d/jiangling/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}


int do_ridewx()
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
	ob->move("/d/wuxi/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�����������ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}

int do_ridecd()
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
	ob->move("/d/chengdu/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳������ɶ��ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}



int do_ridelz()
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
	ob->move("/d/lingzhou/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ݳǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}


int do_rideht()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat ��������"+ob->query("name")+
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

	ob->move("/d/guanwai/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�������ͼ������\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}


int do_ridejingzhou()
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
	ob->move("/d/jingzhou/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�����ﾣ�ݳǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}



int do_ridekm()
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
	ob->move("/d/kunming/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�����������ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}


#include "mafubj.h"
#include "mafusz.h"
#include "mafuhz.h"
#include "mafufz.h"
#include "mafufs.h"
#include "mafudl.h"
#include "mafuyd.h"
#include "mafuyl.h"
#include "mafuem.h"
#include "mafuxy.h"
#include "mafuyz.h"
