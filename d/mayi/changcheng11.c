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
	        "southwest" : __DIR__"changcheng10",
	        "eastup" : __DIR__"changcheng12",
	        "northdown" : __DIR__"dongmen",
	]));
       setup();
	replace_program(ROOM);
}
