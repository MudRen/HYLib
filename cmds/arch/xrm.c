// xrm.c 
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/2
inherit F_CLEAN_UP;
int help();
int rmDir(string );
static int flag; //�ж��Ƿ���ֹ�ݹ���ã������Ƶݹ����(ֻ�������16��ĵ���)

int main(object me, string file)
{
	seteuid(geteuid(me));
	write("X rm ���� v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"��ҳ��http://mud.yn.cninfo.net/jackyboy\n�ʼ���jackyboy@126.com\n");
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	file=resolve_path(me->query("cwd"),file);
	log_file("cmds/xrm.log",
	sprintf("%s(%s) ɾ�� %s on %s\n",
	me->name(1),   //��¼ʹ�����������
	geteuid(me),   //��¼ʹ�������ID
	file,          //��¼ɾ�����ļ�·��
	ctime(time()) ) ); //��¼ʹ�������ʱ��
	flag=0;
	switch(file_size(file))
	{
		case -1:
			write("�Բ�������Ȩɾ�����Ŀ¼(���ļ�)��\n");
			break;
		case -2:
			write("ɾ��Ŀ¼(�ļ�)��...\n");
			if(rmDir(file)==0)
				write("ɾ��ʧ�ܡ�\n");
			else
				write("ɾ���ɹ���\n");
			break;
		default:
			if(rm(file) )
				write("ɾ����ɡ�\n");
			else
				write("��û��ɾ�����������Ȩ����\n");
	}
	return 1;
}

int rmDir(string file)
{
	string tmp;
	if(flag>15)
		return 0;
	reset_eval_cost();
	switch(file_size(file))
	{
		case -1 : 
			flag=16;//���ó����ж�
			write("�����ļ���Ȩɾ��������\n");
			return 0;
			break;
		case -2 :
			//ɾ����Ŀ¼�µ��ļ���Ŀ¼
			if(file[sizeof(file)]!='/')
				file=file+"/";
			foreach(tmp in get_dir(file))
			{
				if(!rmDir(file+tmp))
				{
					flag=16;//�жϣ���Ϊɾ������
					return 0;
				}
			}
			if(!rmdir(file))
			{
				flag=16;//�жϣ���Ϊɾ������
				return 0;
			}
			break;
		default :
			if(!rm(file))
			{
				flag=16;//�жϣ���Ϊɾ������
				return 0;
			}
			break;
	}
	return 1;
}

int help()
{
  write(@HELP

X rm ���� v0.1
Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
��ҳ��http://mud.yn.cninfo.net/jackyboy
�ʼ���jackyboy@126.com


ָ���ʽ : xrm <����>
��ָ�������ɾ����Ȩ�޸ĵĵ���������ɾ����Ŀ¼�ĵ�����
ע�⣺������Ƚ�Σ�գ���С��ʹ�á�
HELP
    );
    return 1;
}
