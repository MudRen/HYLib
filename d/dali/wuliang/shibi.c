// shibi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void check_trigger();
void close_passage();
void reset();
string look_xiaoshi();
string look_dashi();

void create()
{
        set("short", "ʯ����");
	set("long", @LONG
����һ���ʯ��(dashi)�£�������һ��Сʯ�(xiaoshi)��������������
�����ݺύ�����¿ݻƵ���֦��Ҷ���˺ö�㣬�����ܾ�����û�������ˡ�
LONG
	);

	set("exits", ([
	      "out" : __DIR__"shuhou",
	]));
        set("outdoors", "����");
	set("item_desc",([
           "dashi" : (: look_dashi :),
	   "xiaoshi" : (: look_xiaoshi :),
	]));

	setup();
}

void init()
{
	add_action("do_huang", "huang");
	add_action("do_tui", "tui");
        add_action("do_tear", "si");
	add_action("do_tear", "tear");
}

void check_trigger()
{
	object room;

	if( (int)query("up_trigger")>=2
	&& (int)query("down_trigger")>=2
	&& !query("exits/down") ) {
          message("vision", "��ʯ����ת��������һ�ȴ����Ƶģ�"
			"ת��һ�룬�Һ�¶��һ���������ߵĶ�Ѩ��\n", this_object() );
	  set("exits/enter", __DIR__"dongkou");	
          delete("poem_teared");
	  delete("up_trigger");
	  delete("down_trigger");
	  remove_call_out("close_passage");
	  call_out("close_passage", 10);
	  }
}

void close_passage()
{
	object room;
	if( !query("exits/down") ) return;
	message("vision", "��ʯ��Ȼ�����������������������ƻ�ԭ����"
		"�����ڸ�ס�ˡ�\n", this_object() );
	delete("exits/down");
}

int do_tui(string arg)
{
	string dir;
	if( !arg) return 0;
	if (arg == "dashi") {
	 if(!query("poem_teared"))
	   return notify_fail("�������������������Ʋ�����\n");
	 write("�������ƶ������ʯ�����ֿ����ƶ�......\n");
	   return 1;
	   }
	if( sscanf(arg, "dashi %s", dir)==1 && (int)query("poem_teared") ) {
	 if( dir=="right" ) {
	  message_vision("$N����ʯ�����ƣ���ʯ���˻Σ����ƻ�ԭλ��\n",this_player());
          add("up_trigger", 1);
	  check_trigger();
	  return 1;
	  }
	  write("��Ҫ������ʯ�����Ǹ�����\n");
	  return 1;
	  }
      return notify_fail("��Ҫ��ʲô��\n");
}

int do_huang(string arg)
{
	string dir;
	if( !arg) return 0;
	if (arg == "dashi") {
	  if(!query("poem_teared"))
	   return notify_fail("������������������β��ˡ�\n");
	   write("�����Żζ������ʯ�����ֿ����ƶ�......\n");
	   return 1;
	   }
	if( sscanf(arg, "dashi %s", dir)==1 && (int)query("poem_teared") ) {
	  if( dir=="left" ) {
	   message_vision("$N����ʯ����Σ���ʯ���˶������ƻ�ԭλ��\n",this_player());
           add("down_trigger", 1);
	   check_trigger();
	   return 1;
	   }
	   write("��Ҫ������ʯ�����Ǹ�����\n");
	   return 1;
	   }
       return notify_fail("��Ҫ��ʲô��\n");
}

int do_tear(string arg)
{
	string dir;
	if( !arg || arg=="" )  return 0;
	if( arg =="cao" ){
          write("��Ҫ������ !\n");
	  return 1;
	  }
	if( arg=="teng" ) {
	  write("��Ѵ�С��ʯ�������������ȥ��\n");
	  add("poem_teared", 1);
	  return 1;
	}
}

void reset()
{
	::reset();
	delete("poem_teared");
	delete("up_trigger");
	delete("down_trigger");
}

string look_xiaoshi()
{
	return
	 "�ܶ�Ĳ���֮������������档\n";
}

string look_dashi()
{
	return
	"�Ҹ����أ��������һ��С��ʯ֮�ϡ�\n";
}
