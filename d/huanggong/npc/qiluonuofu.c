inherit NPC;
void create()
{
   set_name("����ŵ��",({"qiluo nuofu"}));
   set("gender","����");
   set("age",45);
   set("combat_exp",5000);
   set("mingwang",200);
   set("long","��λ�Ƕ���˹ʹ��.\n");
   set_skill("unarmed",10);
   set_skill("parry",10);
   set_skill("dodge",10);
   set_skill("literate",10);
   set("chat_chance",4);
   set("chat_msg",({
  "����ŵ���:�������ڵȺ�����۵ĽӼ�.\n",
  "����ŵ���:���Ǵ��������Ů,�鱦�����.\n",
  }));
   
   setup();
   add_money("silver",10);
}