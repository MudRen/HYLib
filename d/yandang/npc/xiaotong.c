inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����Сͯ", ({"xiaotong", "xiaohai", }) );
        set("gender", "����" );
        set("age", 14);
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("rank_info/respect", "С��");

        set("inquiry", ([
              "zhuangzhu": "ׯ���ڴ���,��ƽʱ��������!\n",
              "ׯ��": "ׯ���ڴ���,��ƽʱ��������!\n",
              "��": "��˵����ǽ�ϵ��ǰѽ���,ׯ��ƽʱ�������������." ,
]) );


        setup();

        carry_object("/clone/misc/cloth")->wear();
add_money("silver",1);
}
void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	object *inv;
	int count;

        if( !ob || environment(ob) != environment() ) return;
	inv=all_inventory(ob);
	for(count=0;count<sizeof(inv);count++)
	    if(inv[count]->query("name")=="����")
	return;
else
     if(ob->query("family/family_name")=="�㵴��" ) 
  {
  say("����Сͯ��"+ob->query("name")+"����һ���衣\n");
  clone_object(__DIR__"obj/baiyubei")->move(ob);
	return;
}
return;
}
