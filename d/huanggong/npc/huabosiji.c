inherit NPC;
void create()
{
   set_name("����˹��",({"huabo siji"}));
   set("gender","����");
   set("age",45);
   set("combat_exp",51000);
   set("mingwang",200);
   set("long","��λ�Ƕ���˹ʹ��.\n");
   set_skill("unarmed",10);
   set_skill("parry",10);
   set_skill("dodge",10);
   set_skill("literate",10);
   set("chat_chance",4);
   set("chat_msg",({
  "����˹����:�������ڵȺ�����۵ĽӼ�.\n",
  "����˹����:���!���!how are you?\n",
  }));
   
   setup();
   add_money("silver",10);
}