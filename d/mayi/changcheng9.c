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
	        "west" : __DIR__"changcheng8",
	        "northeast" : __DIR__"changcheng10",
                "northdown" : __DIR__"s-road",
                "southdown" : __DIR__"sroad",
	]));
       setup();
	replace_program(ROOM);
}
