inherit NPC;
void create()
{
  set_name("��",({ "man"}) );
        set("gender", "����" );
        set("age", 35);
   set("long", "����һ�������������µ�����\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "�����˱��ã��޸�¥�Ĺ�����Ǻã�������\n",
    "��Ц�����ҡ��ҵ���Ҳ�����ָ����أ�\n",
    "��һ��ü����û��Ǯ��ƺ��ˡ�\n",
    "�������ߴ����������޸�¥�Ĺ��������������\n",
    }));
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
