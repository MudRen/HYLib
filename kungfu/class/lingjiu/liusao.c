// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>


inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ɩ", ({ "liu sao", "liu", "sao" }));
        set("long", @LONG
��ɩ������翷����չ��о���Ų������첿��
���졣����������٣�����ͯ�Ѷ��꣬����
������������˪��
LONG);
        set("title", "��翷����չ�");
        set("nickname", HIR "���첿����" NOR);
        set("gender", "Ů��");
        set("age", 56);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3400);
        set("max_neili", 3400);
        set("jiali", 100);
        set("level", 15);
        set("combat_exp", 1000000);
        set("score", 3000);
        
        set_skill("force", 140);
        set_skill("xiaowuxiang", 140);
        set_skill("dodge", 160);
        set_skill("yueying-wubu", 160);
        set_skill("parry", 140);
        set_skill("strike", 140);
        set_skill("liuyang-zhang", 140);
        set_skill("sword", 160);
        set_skill("tianyu-qijian", 160);
        set_skill("literate", 180);
        set_skill("martial-cognize", 120);

        map_skill("force", "xiaowuxiang");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");

        prepare_skill("strike", "liuyang-zhang");

        create_family("���չ�", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.huan" :),
        }));

        set("master_ob",3);
	setup();

        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") == "����")
        {
                command("hmm");
                command("say �߿������չ�����������ͽ��");
                return;
        }

        if ((string)ob->query("gender") != "Ů��")
        {
                command("sneer");
                command("say ���չ��ֲ��ǻʹ�����һ��̫������������");
                return;
        }

        if ((int)ob->query_skill("xiaowuxiang", 1) < 40) 
        {
                command("say ��ѱ��ŵ��ķ��������������ҡ�");
                return;
        }

        command("nod2");
        command("say �����Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));

        if ((string)ob->query("class") != "dancer")
                ob->set("class", "dancer");
}
