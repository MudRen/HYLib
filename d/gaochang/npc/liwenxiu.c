 //liwenxiu.c ������

#include <ansi.h>


inherit NPC;
int ask_supu();
int ask_parent();
int ask_gaochang();

void create()
{
        set_name("������", ({ "liwenxiu", "li" }));
        set("gender", "Ů��");
        set("age", 18);
        set("long", "�������崿���㣬��ȻһЦ������������Ȼ�Ķ���\n");

        set("combat_exp", 30000);
        set("shen_type", 1);

            set("per", 28);
       set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 40);
        set_skill("sword", 100);
        set_skill("unarmed", 50);
        set_skill("dodge", 100);
        set_skill("parry", 100);

        set("inquiry", ([
                "����" : (: ask_supu :),
                "��ĸ" : (: ask_parent :),
        ]) );


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
// 	    carry_object("__DIR__/obj/map");
}

int ask_supu()
{
 say("��������Ȼ��˵�������Ҷ�ʱ�Ļ�飬�����ںͰ�����һ���ˣ�\n");
 this_player()->set_temp("marks/��1", 1);
 return 1;
}

int ask_parent()
{
object map;
object me;
me=this_player(); 
 if ((int)this_player()->query_temp("marks/��1")) {
 say("���������ʵ�˵�����ҵĸ�ĸ�Ǳ����˺����ģ������������Ǽҵĸ߲���ͼ.\n"
     "��һ��Ҫ���г��ˣ�Ϊ�Ҹ�ĸ����\n");
 this_player()->set_temp("marks/��2", 1);
 say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ�\n"
     "���ҾͰѵ�ͼ�͸���ɡ��㿴���߲��Թ�������ʲô��\n");
 map=new("/d/gaochang/obj/map");
 map->move(me);
 me->start_busy(5);
return 1;
  }
  else {
 say("������˵������ĸ֮�𣬲������졣\n");
 return 1;
  }
}

