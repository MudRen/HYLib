// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("ˮ��", ({ "shui sheng", "shui", "sheng" }));
       set("long", 
       "����ʮ��������ͣ�����ƮƮ��
���������һ�����ƵĴ󻨣���ɫ΢�ڣ���òȴ��Ϊ������\n");
       set("gender", "Ů��");
       set("nickname", HIW"����Ů��"NOR);
       set("age", 20);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 30);
       set("int", 30);
       set("con", 30);
       set("dex", 30);
       set("per", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 500000);
       set("shen_type", 1);

       set_skill("force", 80);
       set_skill("huashan-neigong", 80);
       set_skill("dodge", 80);
       set_skill("huashan-shenfa", 80);
       set_skill("strike", 80);
       set_skill("huashan-zhangfa", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("huashan-jianfa", 80);
       set_skill("literate", 80);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");

       set("inquiry", ([
              "�仨��ˮ": "�㲻�᲻֪�����������Ĵ�Űɣ����½�ˮ᷾����ҵĸ��ס�",
              "Ѫ����ɮ": "����һ��Գ�Ѫ�����棬��ʵ�޶������ҿ�����һ��һ����������",
       ]));

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}
void init( )
{
        call_out("hunting",300);
}

void hunting()
{
object ob=this_object();
if (this_player())
{
message("vision", HIW"ֻ���ö����ᣬ������һ��������һ������Զ�������ˡ�\n"NOR, this_player());
}
destruct(ob);
}