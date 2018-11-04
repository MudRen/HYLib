// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;


inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
        set_name("׿����", ({ "zhuo bufan", "zhuo", "bufan"}));
        set("gender", "����");
        set("title", "һ�ֻ۽�������");
        set("nickname", HIY "����" NOR);
        set("age", 37);
        set("long", @LONG
��ʮ����ǰ��һ�ֻ۽�������ʦͽ��ͯ��ɱ��
���⣬��ʱ׿�������ڸ������������ѣ��Ӵ�
��Ҳ���һ�ȥ���ӵ�����ɽ�л�Ƨ����֮�ؿ�
�н����������е���ǰ��������������һ����
��������������ʮ���꣬���ڽ�����ɣ�����
�����޵С�
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 9500);
        set("max_qi", 9500);
        set("jing", 9200);
        set("max_jing", 9200);
        set("neili", 9800);
        set("max_neili", 9800);
        set("jiali", 150);
        set("level", 30);
        set("combat_exp", 2200000);
set("pubmaster",1);
        set_skill("force", 220);
        set_skill("bahuang-gong", 220);
        set_skill("sword", 240);
        set_skill("zhougong-jian", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("strike", 180);
        set_skill("liuyang-zhang", 180);
        set_skill("parry", 220);
        set_skill("martial-cognize", 220);
        set_skill("literate", 180);

        map_skill("force", "bahuang-gong");
        map_skill("sword", "zhougong-jian");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "zhougong-jian");
        map_skill("strike", "liuyang-zhang");

        prepare_skill("strike", "liuyang-zhang");

        set("inquiry", ([
                "�ܹ���"   : "�������µ�һ������",
                "����"     : "�ۿ��֣���Ȼ�������������ӵ�һ���������۽�����������ҡ�",
                "��ɽͯ��" : "��ɱ����һ�ֻ۽�������ʦͽ���ҿ��������磡",
                "����"     : "�����������չ��µ�����������ȫ���������",
                "������"   : "�����������չ��µ�����������ȫ���������",
                "����"     : "�ҵ��ܹ���������˫������������û�ڶ����ܹ��й���",
        ]));

        create_family("һ�ֻ۽���", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
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
                command("killair");
                command("say ����ʲô����������ϰ�Ҿ���Ľ�����");
                return 0;
        }




        if (skill == "sword" && ob->query_skill("sword", 1) > 179)
        {
                command("hmm");
                command("say ���ˣ�ʣ�µĽ����Լ�ȥ�о���");
                return 0;
        }

        if (! ob->query_temp("can_learn/zhuobufan"))
        {
                command("nod2");
                command("say ��Ȼ�����Ȥ�����������ĵ��ӣ��Ҿͽ��������ܹ�����");
                ob->set_temp("can_learn/zhuobufan", 1);
        }
        return 1;
}


void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "���չ�")
{
        command("smile");
        command("say ���ã����ã�");
        command("say ��һ�ֻ۽���������ͽ�������Ϸ�������㡣");
        command("recruit " + ob->query("id"));
}
}


/*
void unconcious()
{
        die();
}
*/
