inherit NPC;
void create()
{
   set_name("����", ({ "yingwu","bird" }) );
   set("race", "Ұ��");
   set("age", 5);
   set("long", "��ëѤ���ޱȵ����ģ���ģ����˵����\n");
   
   set("str", 10);
   set("cor", 20);
   set("combat_exp",5000);

   set("limbs", ({ "ͷ��", "����", "���", "�ҳ�", "���","�ҽ�" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 5);
   set("chat_msg", ({
  "���ĺ���������Դ�������.\n",
  "����ҡ�����Դ������������˾Ƶ�ģ����\n",
 }));
   set_temp("apply/attack", 5);
   set_temp("apply/armor", 25);

   setup();
}

void die()
{
  message_vision("$N���˼��������������³������.\n",this_object());
  destruct(this_object());
  return;
}