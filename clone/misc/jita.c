// rose.c

#include <ansi.h>;
#include <command.h>;
inherit ITEM;

void create()
{
	set_name("�缪��", ({"dian jita", "jita"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
����һ����ɫ�ģ���COOL�ĵ缪��������ϵ�ż����ң�����tan��
��������һ����������ɡ�
LONG
);
set("no_clone",1);
	set("value", 5000);
	set_weight(10);
	}
	setup();
}
void init()
{
	add_action("do_tan", "tan");
}
int do_tan(string arg)
{
	object me = this_player();
	if( !arg || arg=="") return notify_fail("��Ҫ��ʲô��\n");
	
	if( me->is_busy() )
		return notify_fail("�����ڵ�����\n");

	if( me->query("qi") < 100 )
		return notify_fail("���ٳ��ˣ���û���ģ�\n");
	if( arg == "jita"  || arg == "����"){
	   	message_vision("$N��COOL������һ�ѵ缪��������������������ÿһ���˵��Ļ���\n",me);
	   	me->add("qi",-100);
                me->start_busy(4);
	switch( random(38) ) {
                case 0:
           	message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"Don~t Break My Heart���ٴ����ᣬϲ�����ǳ����������С���\n"NOR,users());
		break;
                case 1:
                message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�ҵ����飬����һ�ѻ�ȼ��������ɳĮ��̫�������ң�Ҳ������ҡ���\n"NOR,users());
		break;
                case 2:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�ҳ��϶��������ǵĻ���������ҹɫ̫����̫���ᡫ��\n"NOR,users());
		break;
        	case 4:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������Ĵ����װ����ң����Ҳ�֪�������㱻�������١���\n"NOR,users());
		break;
		case 5:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"��ҹ�ĺ��罫����˺�飬��ŵĽŲ��Ҳ����飬���ʵ�ϸ�������ʵ�������\n"NOR,users());
		break;
	 	case 6:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"����ô�޵�����Ǳ����Ƿ��Ҷ��㻹������������\n"NOR,users());
		break;
	   	case 7:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"һ���ƣ�����������������������󡫡�\n"NOR,users());
		break;
	   	case 8:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"����ı��������Ϻ��ҵ��ģ�������������ˮ���һ�顫��\n"NOR,users());
		break;
	   	case 9:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"����޵��ǿ޲����������š���\n"NOR,users());
		break;
		case 10:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"˵�������ģ����˸����飬��˵���������кα���д�š���\n"NOR,users());
		break;
		case 11:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�黨���������ã����������ޡ���\n"NOR,users());
		break;
		case 12:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�������������ˣ��������������а�˿��ǧ�ɣ��羭��ɢ�����ơ���\n"NOR,users());
		break;
		case 13:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������ʲô��Ӧ�У�������ʲô����������\n"NOR,users());
		break;
		case 14:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"����ҹ�Ҳ����ң������㱳Ӱ���ɿ�Ц����㣬��֪Ҫ˵�������ϧ��û���ԡ���\n"NOR,users());
		break;
		case 15:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�һ��ȥ�Ҳ�С�ĵ��µ���ˮ������װ��һ�ж�����ν����\n"NOR,users());
		break;
		case 16:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"���ҽ����Ķ�ժ�£��������������ڻ����������������Ƿ��������o覡���\n"NOR,users());
		break;
		case 17:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"��������˵һ�������ǧ��Ҫ����Ϊ�棬��Ҫ���׵ĸ�������ǡ���\n"NOR,users());
		break;
		case 18:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"Ŷ��˼���ã�Ŷ��˼���ã�������һ��̫�����ʹ����\n"NOR,users());
		break;
		case 19:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"Every Sha La La La��Every How How��Sunshine����\n"NOR,users());
		break;
		case 20:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�ҵİ��糱ˮ�����糱ˮ���������ƣ��������棬���糱ˮ�������Ұ�Χ����\n"NOR,users());
		break;
		case 21:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�������ϵ����Ǻ��٣���֪�����ǵ������ˡ���\n"NOR,users());
		break;
		case 22:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"��Ӵ������հݰ�ѽ�¸�վ���������찮��С����\n"NOR,users());
		break;
		case 23:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�����@������ �������N���档\n"NOR,users());
		break;
		case 24:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�¿vʹ����� ���w���L�M�o��\n"NOR,users());
		break;
		case 25:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������������Ը�����۾�,��ƾ����������˯���� ��\n"NOR,users());
		break;
		case 26:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������˳���� ��������� �鰮������ �Ӳ��������ͷ ��\n"NOR,users());
		break;
		case 27:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"̫�밮������ѹ�ֲ��˵���ͷ ��Ҫȫ��ռ�����ϲŭ���\n"NOR,users());
		break;
		case 28:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"Kimi no koe dake dane kokoro ni kagi wo kaketa ano toki wo \n"NOR,users());
		break;
		case 29:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"���������ᡢ�˵��ס��ĳɻ�Ҳ����ν�� \n"NOR,users());
		break;
		case 30:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"���ܿ� ���ܶ� ��һ�ж���Ϊ�˱���ʹ�����˺� ��\n"NOR,users());
		break;
		case 31:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"��Ϊ����Ҫ���� �������ĸо� (����)��\n"NOR,users());
		break;
		case 32:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������������ĸ��� ʹ�ò�֪��ô��ȥ ��\n"NOR,users());
		break;
		case 33:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�������尮�򲻰�֮��ľ��롣\n"NOR,users());
		break;
		case 34:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"����Ҷ�����˷��֪��ԭ����Ʈ�㡣\n"NOR,users());
		break;
		case 35:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"������������ �Ӵ˲����Ű��顣\n"NOR,users());
		break;
		case 36:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"ֻҪ���Ծ��޺�� ���ĸ��ԡ�\n"NOR,users());
		break;
		case 37:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"�� �����Ĥ������� ���Ȥϡ��Ȥ�ơ����Ĥ��� ��\n"NOR,users());
		break;
		case 38:
		message("channel:chat",HIY"��"+me->query("name")+"����II�ݳ��᡽��"HIC"һ���� ������Ͷ��һ���� �������^�� ��\n"NOR,users());
		break;

		}
	return 1;
	}
}
