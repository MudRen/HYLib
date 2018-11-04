// Room: /d/wizhome/incahome/beimen.c
// Date: inca 98/08/13

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "��������¥");
	set("long", @LONG
���Ǳ�������¥�����ڱ����Ļ����񻯣���������ķ�ɳ��ʴ�Ե���Щ�ưܡ�
�������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ
(gaoshi)���ﷸ�����������ӳ����ǣ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס����
���ʡ�һ����ֱ����ʯ�������ϱ��������졣�����ǽ��⣬����ġ�����
�ġ���·�ģ����˴Ҵҡ��ϱ��ǳ��
LONG
	);
        set("outdoors", "city2");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"north" : __DIR__"nroad1",
                "southdown" : "d/beijing/xisi2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}

