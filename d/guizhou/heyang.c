inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ҹ�����ʷ�ƾã���������ʮһ��(��Ԫ1378��)�����ұ���
������600�����ˡ���������������Ϊ�˿������ϱ���ں�������
(��Ԫ1373��)�ù�����ָ��ʹ˾���Կ��ƴ����ᡢ�桢���������
����λ�ڹ���������Ż��Ĺ�(��)��(���������ˮ��)�����֮��
�Σ���������贫�ݹ�����"��"�ʹ��ݾ����"��"��פ����˫ʨ��
������Խ��ͣ�ʷ��"������"��	
LONG );
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
	set("exits", ([
               "west"      : __DIR__"jinyong-cheng",
               "northwest"      : __DIR__"tulu4",
               "south"      : __DIR__"tulu5",		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



