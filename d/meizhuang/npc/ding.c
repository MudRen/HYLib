// ding.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
//inherit F_CLEAN_UP;
// modified by wind

void create()
{
        set_name("����", ({"ding jian","ding",}));
        set("long",
                "���������ӽ��������һ�ֵ罣���ᣬ������÷ׯ���ܼҡ�\n"
        );
        set("gender", "����");
        set("nickname", HIC"һ�ֵ罣"NOR);
        set("attitude", "friendly");

        set("age", 30);
        set("shen_type", 1);
        set("str", 17);
        set("int", 24);
        set("con", 20);
        set("dex", 22);
        set("max_qi", 13350);
        set("max_jing", 12200);
        set("neili", 11350);
        set("max_neili", 11350);
        set("jiali", 1);
        set("combat_exp", 800000);
        set("score", 100);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("sword", 120);
        set_skill("parry", 100);
       set_skill("force", 100);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("literate", 130);
        
        set_skill("kuihua-xinfa", 100);
        set_skill("pomopima-jian",300);
        map_skill("force", "wuzheng-xinfa");        
        map_skill("dodge", "piaoyibu");
        map_skill("force", "pomopima-jian");
        map_skill("sword", "pomopima-jian");
        map_skill("parry", "pomopima-jian");
        create_family("÷ׯ", 2, "����");

        setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/meizhuang/obj/yaoshi");
}


void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say ��÷ׯ��Ȼ����ʲô��������, ����ͽҲ��Ϊ�ϸ�");
                command("say ��Ʒ�з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ����¾��������ˡ�");
        command("recruit " + ob->query("id"));
}