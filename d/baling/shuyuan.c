// baling/shuyuan
// Room in ���� 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ�������������
��̫ʦ���Ͻ�ѧ���ϳ��Ĵ����������ˡ�ս�ҵ�ʱ�����ӵ��������
��������������ѧ��ѧ����һ�����õĵĴ��鰸������������ǰ�棬��
�ϰ��ż��������˵���װ�鼮���������������һ�����(shujia)����
�ڶ��������ʯ�̣������Ժ��ʷ���ƾá�ֵ��һ�����Ƕ�ڽ���ǰ��
�ڵ�ѧ��(xuegui)��
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
   
        "south" : __DIR__"dongdajie1",
]));
        set("objects",([
          __DIR__"npc/zhu":1,
          ]));
        set("item_desc",([
         "shujia":"����һ������ܣ�������˺ܶ��鼮��\n",
         "xuegui":"������ѧ��\n",
         ]));
	setup();
	replace_program(ROOM);
}
