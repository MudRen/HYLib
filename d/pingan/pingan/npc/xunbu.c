// yamen_police.c

inherit NPC;

void create()
{
     string *surname=({"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ",});
     set_name(surname[random(sizeof(surname))]+"Ѳ��", ({ "xun bu","police"}) );
     set("gender", "����" );
     set("age", 25);
     set("str", 45);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long",@LONG
Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����
LONG
);
     set("status","patrol");
     set("CatchWho",0);
     set("combat_exp", 500000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);
     set("chat_msg_combat", ({
                            "Ѳ��˵���������ʲô? ��������ȥ��������!?\n",
                            "Ѳ��˵������! ��Ȼ�ҵ��־ܲ�! ���췴��\n",
                            "Ѳ�����еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
                            "Ѳ��˵����������ˣ����ǹԹԵĸ����߰ɡ�\n"
                            }) );
     set ("inquiry",([
                "bribery":
"˵���ﻰ������̫ү��ƶ���������������µ�������û����������\n"+
"�������Ǯ�ɣ�\n",
                "salary":
"������үٺ��΢�������ǵ�������Ȼ������......\n",
                "money":
"˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸(bribery)��\n����Ҳ�ðǲ�Ƥ\n
",
                        ]));
     set ("chat_chance",99);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      (: random_move :)

                      }) );
     set("pursuer",1);
     set_skill("blade", 100);
     set_skill("parry", 90);
     set_skill("dodge", 70);
     setup();
     carry_object("/clone/weapon/gangdao")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}