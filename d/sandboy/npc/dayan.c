inherit NPC;

void create()
{
   set_name("����", ({ "dayan","wield goose" }) );
   set("race", "Ұ��");
   set("age", 6);
   set("long", "һֻ��Ⱥ�Ĵ���,��«έ�ж������\n");
   
   set("str", 19);
   set("cor", 20);
   set("combat_exp",1000);

   set("limbs", ({ "ͷ��", "����", "���", "�ҳ�", "���","�ҽ�" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
  "����¶����������,�ƺ��ڻ������յĻ��.\n",
  "����̧ͷ������,�۽�����������ˮ.\n",
 }));
   set_temp("apply/attack", 8);
   set_temp("apply/armor", 10);

   setup();
}
void die()
{
  message_vision("$N����һ��,����˫��,������.\n",this_object());
  new(__DIR__"egg.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}