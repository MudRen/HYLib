// ����˫����
 
// girl.Ů�ӡ�

inherit NPC;

void create()
{
  set_name("ˮ��", ({"shui shou","shui","shou"}));
  set("long","������ս���Ϲ�����һ��ˮ�֡�\n");
  set("gender", "����");
  set("combat_exp", 20000);
  set("age", 18);
  set("attitude", "peaceful");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  setup();
  carry_object("/d/gaoli/obj/sengyi")->wear();
}


