inherit NPC;
void create()
{
  set_name("����",({ "shu sheng","shu","sheng"}) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����һ�����ʫ���������\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "����̾�������ʱ�����ң�����ô���г�ͷ֮���أ�\n",
    "�����������ܣ��������ĳ�ɳ������������ˣ�\n",
    "����̾�����ҿ���һ����ѧ�ʣ�ȴû�ط��ð���\n",
    "����ҡҡͷ���������Լ�������顣\n",
    }));
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
