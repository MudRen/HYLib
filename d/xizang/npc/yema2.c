 // mind_beast.c
inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
    set_name("�׿���", ({ "white horse" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
    //set("long", "һƥƤë������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n");
        set("long",(: horsedesc :));
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("max_jing", 3000);
        set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
        "�׿����ԡ������ԣ������쳤�˼���\n",
        }) );
        set("combat_exp", 5000000);
        set_temp("apply/attack", 300);
        set_temp("apply/armor", 100);
        set_temp("apply/dodge",300);
        set_temp("apply/damage",200);
        
        setup();
}
void init()
{
        ::init();
        add_action("do_xunfu","xunfu");
        add_action("do_ride","ride");
}
string horsedesc()
{
        object me;
        me = this_player();
        if (me ->query_temp("marks/ѱ��_�׿���"))
        {       
                return "ŭ���޴����ˣ���ֻ�����ϣ�ride����Ұ��Ծ��ŭ����";
        }
        return "һƥƤë���׵�Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n";
} 
int do_xunfu(string arg)
{
        object me;
        if (arg != "�׿���" && arg != "white horse" && arg != "Ұ��")
        {       
                return 0;
        }
        me = this_player();
        if (me->query_temp("marks/ѱ��_�׿���"))
        {
                return 0;
        }
        message_vision("$N��˻һ������β̤�㣬���߿񱼣�Ӳ��Ҫ��$n������������ \n",this_object(),me);
        if ((me->query_skill("dodge",1)>=50 && me->query("cor")>=10 && me->query("kar")>=(10+random(10)))||me->query_skill("animal-training",1)>=80)
        {
        message_vision(HIC"$n����ץס���ף�����$N������������̩ɽ�㸽������\n "NOR,this_object(),me);
        message_vision("$N���ڰ�����������ѱ���ش��Ŵ�������\n$n�����������$N��ͷ��������Ծ��������\n",this_object(),me);
                if (!me->query("marks/ѱ��_Ұ��"))
                {
                        me->add("potential",500);
                        me->add("score",100);
                        tell_object(me,"�㱻�����ˣ�\n��ٵ�Ǳ��\nһ�ٵ��ۺ�����\n\n");
                        me->set("marks/ѱ��_Ұ��",1);
                } 
                me->set_temp("marks/ѱ��_�׿���",1);
        }else
        {
                message_vision("$n���ڲ�֧����$N����ˤ��������\n",this_object(),me);
                me->unconcious();
        }
        return 1;
} 
int do_ride(string arg)
{
        object me;
        if (arg != "�׿���" && arg != "white horse" && arg != "Ұ��")
        {       
                return 0;
        }
        me = this_player();
        if (!me->query_temp("marks/ѱ��_�׿���"))
        {
                return 0;
        }
        message_vision(HIC"$n�����������쳤Хһ������������˫�ȼн���������һ��$N���� ��\n\n"NOR,this_object(),me);
        if (random(10))
        {
                message_vision(HIW"$N���Ծ����һ���������ҡ���Խ������һ����̬�����ƣ�����ĺ���ë 
��ɽ�������ɵ�Ʈ����������пգ�������ﻮ��һ�������Ļ��ߣ��������� 
Զ����Ũ��� \n"NOR,this_object(),me);
                me->move("/d/xizang/nujiang");
                message_vision("$N�������󣬳��Ű׿�����������\n",me);
                message_vision("$NԾ�������׿���̤���ȥ��\n",me);
        }else
        {
        message_vision(RED"$N���Ծ�𣬽߾�ȫ����ǰ����������������������˻һ����׹��ŭ����"NOR,this_object());
                message_vision(RED"��׹���һɲ�ǣ�$N�󱳹��𣬶���������ţ������һ˿������$n�������¡�\n",this_object(),me);
                if(random(10))
                {
                        me->unconcious();
                }else
                {
                        me->die();
                }
        }
        destruct(this_object());
        return 1;
}   
