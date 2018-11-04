// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();

void create()
{
        set_name("������", ({ "zuo zimu", "zuo", "zimu"}));
        set("gender", "����");
        set("title", "�������ɶ�������");
        set("age", 54);
        set("long", @LONG
������������ɶ������������£�ֻ������ʮ
������ͣ�������������������硣��������
��һ����������ؽ�����ʵ�˵á�
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 5800);
        set("max_qi", 5800);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 120);
        set("level", 20);
        set("combat_exp", 2000000);

        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        // set_skill("dahai-wuliang", 180);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("sword", 180);
        set_skill("wuliang-jian", 180);
        set_skill("strike", 180);
        set_skill("liuyang-zhang", 180);
        // set_skill("unarmed", 160);
        // set_skill("liuhe-quan", 160);
        // set_skill("claw", 160);
        // set_skill("da-qinna", 160);
        set_skill("parry", 180);
        set_skill("martial-cognize", 160);
        set_skill("literate", 160);
set("pubmaster",1);
        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "xiaowuxiang");
        map_skill("sword", "wuliang-jian");
        map_skill("parry", "wuliang-jian");
        map_skill("strike", "liuyang-zhang");

        prepare_skill("strike", "liuyang-zhang");

        set("inquiry", ([
                "������"   : "�����������չ��µ�����������ȫ���������",
                "����"     : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("��������", 22, "��������");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�"  && ob->query("family/family_name") != "��ң��")
        {
                command("say �����ز���ʶ����̸���ϡ�ָ�̡����֣�");
                return 0;
        }



        if (! ob->query_temp("can_learn/zuozimu"))
        {
                command("say ��Ȼ�������������Ե��ˣ���Ҳ�͹�����������ˡ�");
                ob->set_temp("can_learn/zuozimu", 1);
        }
        return 1;
}




void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "���չ�")
{
        command("nod2");
        command("say �����Ժ�͸����Һ��ˡ�");
        command("recruit " + ob->query("id"));
}
}


/*
void unconcious()
{
        die();
}
*/
