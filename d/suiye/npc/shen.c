 
// jia.c

inherit NPC;
inherit F_DEALER;

void create()
{
//  reload("suiye_shendaifu");
  set_name("����", ({"shen daifu", "shen", "daifu"}));
        set("title", "ҩ���ƹ�");
        set("gender", "����");
  set("shop_id",({"shen dafu", "shen", "dafu"}));
  set("age", 37);
  set("combat_exp", 30000);
   set("long","��������Ҷ�������Ĵ��,ÿ�����������������ﲻ��.\n");
  set("age", 38);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);

  setup();
  
}


int regenerate()
{
        set("called", 0);
        return 1;
}
