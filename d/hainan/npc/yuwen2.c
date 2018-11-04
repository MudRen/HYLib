// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("��������", ({ "yu weng", "fisherman", "laoyuweng" }) );
	set("gender", "����" );
	set("age", 60+random(10));
	set("long", "����һλ��������������,����������,��Ȼ�Եá�
��������������,�����������������������.\n");

	set("combat_exp",4000);


	set_skill("dodge", 110);
	set_skill("unarmed", 110);

	setup();
	carry_object("/d/hainan/obj/shuoyi")->wear();
}
void init()
{
   add_action("do_ask","ask");
}
void on_board()
{
	object ob,room;
      room = load_object("/d/hainan/duchuan");
	room->delete("exits/out");
      room = load_object("/d/hainan/haibian");
	room->delete("exits/enter");
		message("vision", "�����̰�̤�Ű�����������������������������ӿ�Ĵ���ʻȥ��\n",room );	
		message_vision("$N��̤�Ű�����������������������������ӿ�Ĵ���ʻȥ��\n",this_object());	
remove_call_out("on_board");
		if( clonep(this_object()) ) call_out("arrive", 30);
	else
		this_object()->move("/d/hainan/haitan");
}

void arrive()
{
	object ob,room;
      ob=this_player();
   if (living(ob)&&environment(ob)==environment())  {
	room = load_object("/d/hainan/haibian");
      message_vision("�����̰�һ��̤�Ű���ϵ̰�����:������\n",this_object());
      message("vision", "����ҡ��һ��С����С��������ͣ���˸۱ߡ������һ��̤�Ű���ϵ̰���\n",room);
		message_vision("$N˳��̤�Ű����ϰ�ȥ��\n",ob);
		message("vision",ob->name()+"˳��̤�Ű����ϰ�����\n",room);
		ob->move("/d/hainan/haibian");
      message("vision", "����������̤�Ű壬�����İ�С��ʻ��󺣡�\n",room);
    }
	this_object()->move("/d/hainan/haitan");
    return;
}

int do_ask(string arg)
{
	object me,room;

	me=this_player();	
	
      if((arg!="yu weng about out")&&(arg!="yu weng about ����")) return 0;
	message_vision("�����̴Ӵ�ʯ�����ϳ�һ��С������$N��:��λ�͹�,�ϴ��ɡ�\n",me);
	load_object("/d/hainan/haitan")->set("exits/enter","/d/hainan/duchuan");
	this_object()->move("/d/hainan/duchuan");
	load_object("/d/hainan/duchuan")->set("exits/out", "/d/hainan/haitan");

	if( clonep(this_object()) ) call_out("on_board", 10);

      return 1;
}
