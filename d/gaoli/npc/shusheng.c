// ����˫����
 
//������

inherit NPC;

void create()
{
  set_name("����", ({"shu sheng","shu","sheng"}));
  set("long","���Ǹ�����һ��������������ʫ�顣\n");
  set("gender", "����");
  set("combat_exp", 3000);
  set("age", 20);
  set("attitude", "peaceful");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
}


