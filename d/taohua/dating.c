#include <ansi.h>
inherit ROOM;

string look_bagua();
void create()
{
    set("short", "�һ�ɽׯ����");
    set("long", 
"�������һ�ɽׯ����������������ʮ�ֿ��������й����˸���\n"
"���ҵ��鷨�漣���������۵��������йҵ�һ��������\n\n"
   
BLU "            �һ�Ӱ�����\n"
    "            �̺�����������\n\n"
NOR

"�����پ�ͦ�Σ����ƺ�ΰ��\n\n"

"�������֮�϶��Ű�Ƭ��Ƭ�� ��������(bagua)ͼ����ȴ�ֲ���Ѱ��
�İ�����ô�ŵ����룬�������䣬��б���ƣ���Ȼ�����ܵĲ��ü���Э����\n"
);
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("item_desc", ([
		"bagua" : (: look_bagua :),
	]) );

	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	    "/d/biwu/champion_th":1
	]) );    
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("no_beg", "1");
	setup();
	 "/clone/board/taohua_b"->foo();	
//	replace_program(ROOM);
}
string look_bagua()
{
	int i, j, temp;
	int *bagua = ({0,1,2,3,4,5,6,7});
	string *bagua_name = ({"��","��","��","��","��","��","��","Ǭ"});
	string result;
	object me = this_player();

	for (i = 0; i < 8; i++)
	{
		j = random(8);
		while (j == i)
			j = random(8);
		temp = bagua[i];
		bagua[i] = bagua[j];
		bagua[j] = temp;
	}		
	for (i = 1; i < 9; i++)
		me->set_temp("bagua_" + i, bagua[i - 1]);
	result = "һ����ֵ������ԣ����水˳ʱ��˳�������ţ�";
	for (i = 0; i < 8; i++)
		result += bagua_name[bagua[i]];
	return result + "��\n";
}
