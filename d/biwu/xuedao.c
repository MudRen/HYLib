// /kungfu/class/xueshan/xuedao.c  Ѫ������
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ѫ������", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�
LONG
        );
        set("title",HIR"Ѫ���ŵ��Ĵ�����"NOR);
        set("gender", "����");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 50);
        set("combat_exp", 2500000);
        set("score", 180000);

        set_skill("lamaism", 150);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 250);
        set_skill("sword", 120);
        set_skill("dodge", 380);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 380);
        set_skill("hand", 280);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 280);
        set_skill("xue-dao", 380);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );
        set_temp("apply/attack", 300);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

        create_family("ѩɽ��", 4, "����");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "ѩɽ��")
        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��ŵ��ӣ�������ذɣ�\n");
                return;
        }
        if ((int)ob->query("shen") > -100000)
        {
                command("say ���ǲ����������������ɱ�˶����ᣡ\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 60)
        {
                command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "Ѫ���ŵ��������" NOR);
}
