// ����˫����
 
// girl.Ů�ӡ�

inherit NPC;

void create()
{
  set_name("ɮ��", ({"seng ren","seng","ren"}));
  set("long","�����龲�µ�ɮ�ˣ��������ƹ��������\n");
  set("gender", "����");
  set("class","bonze");
  set("combat_exp", 90000);
  set("age", 18);
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  setup();
  carry_object("/d/gaoli/obj/sengyi")->wear();
}


