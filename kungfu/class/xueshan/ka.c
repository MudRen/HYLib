// /kungfu/class/xueshan/gelunbu.c  ���ײ�
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_fashi();
void create()
{
        set_name("�������", ({ "kaneiba", "kaneiba" }));
        set("long",@LONG
���������ѩɽ���л���ɮ���ĸ�ͷ�졣ͬʱ���µ��Ӵ����书��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("nickname", HIG "ɮ��ͷ��" NOR);
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 200);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 10000);
        set("max_jing", 5000);
        set("neili", 10000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 800000);
        set("score", 40000);

        set_skill("lamaism", 280);
        set_skill("literate", 130);
        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        set_skill("dodge", 175);
        set_skill("shenkong-xing", 170);
        set_skill("parry", 160);
        set_skill("cuff", 100);
        set_skill("staff", 180);
        set_skill("xiangmo-chu", 370 );
        set_skill("unarmed", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("sword", 160);
        set_skill("mingwang-jian", 160);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");


        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
}


void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        command("say �Ҿʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","ѩɽ���׼ҵ���");
        }
        else    {
                ob->set("title",HIY"С����"NOR);
        }
}
