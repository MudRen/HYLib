inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ��ǵ�һ�����ڣ��س����ӳ��ǣ�ÿ����ʮ�ｨ��һ������
����פ�����ӣ��������������ߵİ��ڣ�ƽ�������صĹٱ���������Ѳ
�ߣ�����������ͻ�ʵ������ˣ�����Ҳ��û��������
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
	        "northwest" : __DIR__"changcheng5",
	        "southeast" : __DIR__"changcheng7",

	]));
       setup();
	replace_program(ROOM);
}
