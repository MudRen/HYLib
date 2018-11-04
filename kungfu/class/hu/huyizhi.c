// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("����֮", ({ "hu yizhi", "hu", "yizhi" }));
        set("gender", "����");
        set("nickname", HIR "������" NOR);
        set("character", "��������");
        set("age", 37);
        set("long", @LONG
���˺������꣬ͷ�Ϲ���һΧ�׽���������
һ˫��Ь��ȫȻһ����ũģ����
LONG);
        set("attitude", "peaceful");
        set("str", 36);
        set("int", 28);
        set("con", 31);
        set("dex", 33);
    
        set("qi", 24000);
        set("max_qi", 24000);
        set("jing", 22000);
        set("max_jing", 22000);
        set("neili", 24500);
        set("max_neili", 24500);
        set("jiali", 160);
        set("level", 40);
        set("combat_exp", 8000000);

        set_skill("force", 440);
        set_skill("lengyue-shengong", 440);
        set_skill("blade", 460);
        set_skill("baisheng-daofa", 460);
        set_skill("hujia-daofa", 440);
        set_skill("dodge", 440);
        set_skill("sixiang-bufa", 440);
        set_skill("parry", 440);
        set_skill("strike", 440);
        set_skill("tianchang-strike", 440);
        set_skill("cuff", 440);
        set_skill("hujia-quan", 440);
        set_skill("throwing", 400);
        set_skill("mantian-xing", 400);
        set_skill("literate", 380);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "baisheng-daofa");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "tianchang-strike");
        map_skill("cuff", "hujia-quan");
        map_skill("throwing", "mantian-xing");

        prepare_skill("strike", "tianchang-strike");
        prepare_skill("cuff",   "hujia-quan");

        create_family("�������", 13, "����");

        set("inquiry", ([

                "������"   : "�������Ѿ����ˣ�������������",
                "��ԲԲ"   : "������Ҳû�ܺ���˵�ϼ��仰��",
                "��԰԰"   : "������Ҳû�ܺ���˵�ϼ��仰��",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.heng" :),
                (: perform_action, "cuff.kuai" :),
                (: perform_action, "strike.huang" :),
                (: perform_action, "dodge.fei" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        

        set("master_ob",5);
	setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

string ask_me()
{
        object ob, me;

        me = this_player();
        if (me->query("family/family_name") != "�������")
                return "���������ó��ı��£���Ҫ��Ҫ����������\n";

        return "�ܺ�... �ܺ�... ��Ȼ�Ǻ��ҵ��ӣ���û����Ȥѧѧ�ҵİ�ʤ������";
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "�������")
        {
                command("say ��͵ѧ���Ǻ��Ҿ������ٺ�...");
                return -1;
        }

        if (skill != "baisheng-daofa")
        {
                command("say ��ֻ�����ʤ������������������ʦ��ȥѧ�ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/huyizhi/baisheng-daofa"))
        {
                command("say �ã��㿴����ˣ�");
                ob->set_temp("can_learn/huyizhi/baisheng-daofa", 1);
        }

        return 1;
}


