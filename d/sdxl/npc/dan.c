// /u/poq/sdxl/obj/gshedan.c �����ߵ�
// by poq@jyqx 97/7
// amend dubei

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
    set_name("������", ({"she dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "ö");
            set("unique", 1);
        set("long", "����һö����ɫ��Բ�ң������ȳ���\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
    object me = this_player();

    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

       me->add("max_neili", random(10));
       me->add("neili",900);

    message_vision("$N����һö�����ߵ���ֻ������֭Һ�ȼ��༫���ѳ��ޱȡ�!\n", me);
    destruct(this_object());
    return 1;
}
