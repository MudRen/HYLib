
inherit NPC;

void create()
{
   set_name("����",({ "da gouxiong","gouxiong","bear"}) );
        set("race", "Ұ��" );
        set("combat_exp",800000);
        set("max_qi",4000);
        set("max_jing",4000);
        set("max_sen",4000);
     set("long", "����һֻ�����ε��Ĵ��ܣ����׺ݵؿ����㡣\n");
	 set("verbs",({"bite","claw","hoof"}));
    set("limbs",({"ͷ","β��","����","����"}));
    set("attitude","aggressive");
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/xiongpi");
   ob->move(environment(this_object()));
   message_vision("$N��ͷ����һ�����ڵ�һ�µ����˵��ϡ�\n",this_object());
   destruct(this_object());
   return;
}

