
inherit NPC;

void create()
{
   set_name("��",({ "she"}) );
        set("race", "Ұ��" );
     set("long", "����һ���ߡ�\n");
	 set("verbs",({"bite"}));
     set("limbs",({"ͷ","β��","�ߴ�"}));
	 set("attitude","aggressive");
  setup();

}

void die()
{
	object ob,corpse;
	ob=this_object();
	message_vision("$N���ڵ��ϻ��˻Σ����˹�ȥ��\n",ob);
    corpse=new(__DIR__"obj/shedan");
	corpse->move(environment(ob));
	destruct(ob);
	return;
}
