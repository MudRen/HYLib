#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();
mixed ask_skill();

void create()
{
        set_name("ɣ����", ({ "sang tugong", "sang", "tugong"}));
        set("gender", "����");
        set("title", "�������׶�����");
        set("age", 58);
        set("long", @LONG
����Ǵ������׶�������ɣ������ֻ�������
��С���뷢�԰ס��ֳ�һ����ͭ������������
��һ����ɣ���֣����Ǽ���С�ߡ����֮����
�ɣ�ͭ�̰�쵣�����һ�����
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    set("pubmaster",1);
        set("qi", 8200);
        set("max_qi", 8200);
        set("jing", 8000);
        set("max_jing", 8000);
        set("neili", 8800);
        set("max_neili", 8800);
        set("jiali", 100);
        set("combat_exp", 2000000);

        set_skill("force", 180);
       // set_skill("shennong-xinjing", 180);
        set_skill("dodge", 200);
        set_skill("feiyan-zoubi", 200);
        set_skill("strike", 180);
        //set_skill("dusha-zhang", 180);
        set_skill("hand", 180);
        //set_skill("lansha-shou", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        //set_skill("shennong-zhang", 180);
        set_skill("throwing", 220);
        set_skill("pidi-shenzhen", 220);
        set_skill("literate", 160);
        set_skill("poison", 200);
        set_skill("martial-cognize", 180);
set_skill("xiaowuxiang", 180);
set_skill("martial-cognize", 180);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "xiaowuxiang");
        map_skill("throwing", "pidi-shenzhen");
        map_skill("parry", "pidi-shenzhen");
        //map_skill("staff", "shennong-zhang");

        //prepare_skill("hand", "lansha-shou");
        //prepare_skill("strike", "dusha-zhang");

        set("inquiry", ([
                "��ڽ���"   : (: ask_me :),
                "����"       : "�����������չ��µ�����������ȫ���������",
                "������"     : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("���׶�", 8, "����");

        set("zhen_count", 3);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({

                (: perform_action, "throwing.huan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/weapon/gangzhang");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"jinzhen")->wield();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�"  && ob->query("family/family_name") != "��ң��")
        {
                command("bite");
                command("say �����������ҿ�ûʱ�����ġ�");
                return 0;
        }

  
        if (skill == "throwing" && ob->query_skill("throwing", 1) > 179)
        {
                command("say �㰵���������Ѿ��ܸ��ˣ�ʣ�µľ��Լ�ȥ�о��ɡ�");
                return 0;
        }

        if (! ob->query_temp("can_learn/sangtugong"))
        {
                command("bored");
                command("say ���������������ķ��ϣ��ҽ�����ˡ�");
                ob->set_temp("can_learn/sangtugong", 1);
        }
        return 1;
}


mixed ask_me()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "���׶�")
                return "�������ҿ�ûʱ�����ġ�";


        if (me->query_skill("pidi-shenzhen", 1) < 100)
                return "��ٵ�������ַ��������ң���������Ҳûʲô�á�";

        if (query("zhen_count") < 1)
                return "û�ˣ�û�ˣ����ϵ׶������Ƹɾ��ˡ�";

        add("zhen_count", -1);
        ob = new(__DIR__"jinzhen");
        message_vision("$N�ó���ʮ��" HIR "��ڽ���" NOR "(Lanwu jinzhen)��$n��\n",
                       this_object(), me);
        ob->move(me, 1);
        return "���������ڽ���������ȥ�ðɡ�";
}


void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "���չ�")
{

        command("sigh2");
        command("say �����������ʲô�˶��У�������ô�����ɲ��ݣ�ȴ�������ҡ�");
        command("say ����Ҳ��ó�������Ȼ���ˣ��Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
}
} 

