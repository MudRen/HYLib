// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�������ܵ���ǰ����Լ�ܿ������⣬����һЩ�����������ӵ������ˡ���
�ߵ�����ǰ�����̿�������Ϥ�ĵ�·��
LONG
	); 

	set("exits", ([
	      "out" : __DIR__"xiaoxi",
              "northup" : __DIR__"midao4",
	]));

	setup(); 
}

int valid_leave(object me, string dir)
{
      if ( dir == "out"){
       write("\n����õص���ǿ����ҫ��һʱ֮�侹Ȼ�������ۡ�\n\n");
       }
       return 1;
//     return ::valid_leave(me, dir);
}
