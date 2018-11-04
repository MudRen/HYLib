// tang buping.c �Ʋ�ƽ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ʋ�ƽ", ({ "tang buping", "tang" }));
        set("nickname", HIW "������" NOR);
        set("long",
                "�������ŵڰ˴����ӣ��ǽ�����һ�����������������\n"
                "����Լ��ʮ���࣬���ϻ�����һ�ɺ�������\n");
        set("gender", "����");
        set("age", 22);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 100000);
        set("score", 10000);

        set_skill("force", 70);
        set_skill("biyun-xinfa",70);
        set_skill("dodge", 70);
        set_skill("qiulinshiye", 70);
        set_skill("strike", 60);
        set_skill("unarmed",60);
        set_skill("biye-wu", 60);
        set_skill("parry", 70);
        set_skill("throwing", 70);
        set_skill("zhuihun-biao", 70);
        set_skill("literate", 80);

        map_skill("force", "biyun-xinfa");
        map_skill("dodge", "qiulinshiye");
        map_skill("strike", "biye-wu");
        map_skill("unarmed","biye-wu");
        map_skill("parry", "zhuihun-biao");
        map_skill("throwing", "zhuihun-biao");

        create_family("����", 8, "����");
        set("class", "tangmen");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({

                (: perform_action, "strike.meng" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        add_money("gangbiao",300);
	carry_object("/d/tangmen/obj/zhuyebiao")->wield();
        carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �ðɣ��Ҿ������㡣");
        command("recruit " + ob->query("id"));
}
