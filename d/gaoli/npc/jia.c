// ����˫����
 
// jia.c

inherit NPC;
inherit F_DEALER;

void create()
{
 
  set_name("�ִ��", ({"jia daifu", "jia", "daifu"}));
        set("title", "ҩ���ƹ�");
        set("gender", "����");
  set("shop_id",({"jia dafu", "jia", "dafu"}));
  set("age", 37);
  set("combat_exp", 30000);
   set("long",
"�ִ���Ǹ��������������Ĵ��,ÿ�����������������ﲻ��.\n");
  set("age", 38);
 set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);

  setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
}



