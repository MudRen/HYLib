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
set("exits", ([
	        "eastdown" : __DIR__"huangtu1",
	        "southwest" : __DIR__"changcheng2",

	]));
	set("valid_startroom", 1);
       setup();
	replace_program(ROOM);
}
