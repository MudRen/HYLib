//wangqier     written by jhon darks
#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("�����", ({ "wang qier", "wang", "qier","�����" }) );
        set("nickname", HIR " �ĵ�ɽ��ˮ��" NOR);
        set("gender", "����");
        set("age", 19);
        set("long",
                "��˵���˵�����ɣ�����������ᣬȴ�ö�����������\n����һ�����ѽ�������ɣ�����Ҳ�Ǹ���ͽ������\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 10);
        set("cor", 30);
        set("dur", 30);
        set("agi", 40);
        set("int", 24);
        set("cps", 30);
        set("per", 18);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������Цһ�����������ѵ���������һ�ģ�������\n",
                "�������̾һ�������껨ʯ�껨ʯ��������\n",
        }) );

        set("inquiry", ([

                "�껨ʯ" : "ʰ֮��ϧ����֮��̾������\n",
        ]) );

        set("max_sen",3000);
        set("max_gin",3000);
        set("max_kee",3000);
        set("force", 2000);
        set("max_force", 2000);
        set("combat_exp", 600000);
        set("score", 5000);
 
        set_skill("unarmed", 100);
        set_skill("force", 100);

        set_skill("begging",120);

 
        set_skill("dodge",100);
        set_skill("literate",100);
        set_skill("throwing",120);
     

        set("title", GRN"������ؤ"NOR);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
