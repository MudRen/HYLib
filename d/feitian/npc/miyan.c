// miyan.c ����
// ����(diabio)2003.3.21
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("����", ({"mi yan", "yan"}));
        set("gender", "����");
        set("nickname", HIM"���������"NOR);
        set("age", 16);
        set("long",
            "��������糴彣�Ĺ�ͬ�Կ���ʮ�е�����,���ɹ�������һ\n"
            "ʮ��֮�۽�����,���ѷ�������������Ż������ڻ��ͨ��\n"
            "��Ϊ������һ�����Ľ���.���������������¶��һ�ɲ��������顣\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
        }));

        set("qi", 8500);
        set("max_qi", 8500);
        set("jing", 1800);
        set("max_jing", 1800);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 20);

        set("combat_exp", 1480000);
        set("score", 100000);

        set_skill("force", 100);
        set_skill("shayi-xinfa", 160); 
        set_skill("blade", 100);
        set_skill("huoxinliu-jianfa",160); 
        set_skill("dodge", 100);
        set_skill("wuxing-dun", 160);  
        set_skill("parry", 100);
        set_skill("unarmed",100);
        set_skill("shayi",100);
        set_skill("aikido", 100);    
        set_skill("literate",100);
//        set_skill("bearart",100);

        map_skill("force", "shayi-xinfa");
        map_skill("blade", "huoxinliu-jianfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "huoxinliu-jianfa");
        map_skill("unarmed", "aikido");
        prepare_skill("unarmed", "xuanhualiu-quanfa");

        create_family("����������", 8, "����");

        set("inquiry", ([
                "����������" :  "���������������������Ľ�����\n",
      "С��":     "����ţ������£�������������",
      "糴彣��":     "�����˵���ܵ�ɽ������ʦ��ѧϰʣ�µĽ���ȥ�ˡ�",
        ]) );

        setup();

      carry_object(__DIR__"obj/hefu")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
          carry_object(__DIR__"obj/zhujian")->wield();

}

void attempt_apprentice(object ob)
{
        command("say �ðɣ��Ҿ�������,���һ��ѧϰ��");
        command("recruit " + ob->query("id"));
	ob->set("title",HIR"����Ż�������"HIW"������"NOR);
       ob->set("class", "yujianliu");
}


