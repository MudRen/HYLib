// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("��������", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "�����޵�" NOR );
    set("title", HIM"������̽���"NOR);
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ���������ܡ���\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 66);

    set("chat_chance", 1);
    set("chat_msg", ({
 "��������̾�˿����������� ���� �ҵ�����....����ô��������,�Һ�\n"
 "������ ������������������¶������ã��\n",
        }));
    set("inquiry", ([
        "����ͤ"   : "���ֱ���Ұ��˵�����,������ѽ�� \n",
        "��������" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
    ]));

    set("guard/flag", 1);
    set("guard/ok", 1);
    set("qi", 34000);
    set("max_qi", 34000);
    set("jing", 31000);
    set("max_jing", 34000);
    set("neili", 68500);
    set("max_neili", 68500);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

    set_skill("cuff", 250);
    set_skill("strike", 250);
    set_skill("force", 380);             // �����ڹ�
    set_skill("finger", 250);            // ����ָ��
    set_skill("unarmed", 250);           // ����ȭ��
    set_skill("dodge", 380);             // ��������
    set_skill("parry", 380);             // �����м�
    set_skill("sword", 380);             // ��������
    set_skill("pixie-jian", 380);        // ��а����
    set_skill("changquan", 300);         // ̫�泤ȭ
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua-xinfa", 380);      // �����ķ�
    set_skill("kuihua-dafa", 380);      // ������
    set_skill("kuihua-feiying", 380);      // ��������
        
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "pixie-jian");
    create_family("�������", 1, "����");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "parry.huanying" :),
                (: perform_action, "parry.sanlianci" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 900);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
    setup();
    carry_object("/d/heimuya/npc/obj/qijue")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�\n");
                return;
    }
    if (ob->query("gender") !="����" ) {
        command("say Ҫ���񹦣������Թ���");
              return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say �Һ�ľ�������������������������ֳ�������򽻵�������ذɣ�;\n");
                return;
        }
    command("say �ܺã��ܺá�\n");
    command("recruit " + ob->query("id"));
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "��ľ��") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("�������ܿ��˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        ob->add_temp("tmark/��", -1);
        return 1;
}



int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                if (!(int)who->query_temp("tmark/��",)) who->set_temp("tmark/��",100);
                message_vision("�������ܿ��˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�����ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 100);
                return 1;

        }
        return 0;
}