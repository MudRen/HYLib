// ����˫����
 
// girl.Ů�ӡ�

inherit NPC;

void create()
{
  set_name("С��", ({"girl"}));
  set("long","���Ǹ�����һ��С�㣬���������й䡣\n");
  set("gender", "Ů��");
  set("combat_exp", 3000);
  set("age", 18);
  set("per", 29);
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  set("inquiry",([
    "�����":"��������Ҳ�Ǹ������أ����ǲ�֪���𣿣�\n",
    "yanyan":"����ʵ�ǳ����ˣ�Ҳ�������ڵĸ����ˡ�\n",
    ]));
  setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
}


