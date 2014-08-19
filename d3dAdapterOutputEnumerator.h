/*
 *	@file		d3dAdapterOutputEnumerator.h
 *	@data		2014-08-20 00:15
 *	@author		zhu qing quan	
 *	@brief		ʹ��DXGI��ȡϵͳ�м�⵽�������Կ���IDXGIAdapter)����ʾ��(IDXGIOutput)����
 */

#include <DXGI.h>
#include <vector>

/**
  *	@name		DXGI_getAdapters
  * @brief		get all Adapter(video card) in this host
  *	@param[out]	std::vector<IDXGIAdapter*>& adaptersVec �������е�Adapter���󣬴˲���ԭ�е�Adapter�����ͷš��»�ȡ��Adapter���󽫻���뵽vector�ĺ���
  *	@return		HRESULT S_OK--�ɹ�  Other--����
  */
HRESULT DXGI_getAdapters(std::vector<IDXGIAdapter*>& adaptersVec);

/**
  *	@name		DXGI_getOutputs
  * @brief		��ȡ�������ӵ��Կ�adapter�е�����豸����ʾ����
  * @param[in]	IDXGIAdapter1* adapter �Կ�Adapter����
  *	@param[out]	std::vector<IDXGIOutput*>& outputVec �����������ӵ��Կ�adapter�е�����豸����ʾ�������˲���ԭ�е�Output�����ͷš��»�ȡ��Output���󽫻���뵽vector�ĺ���
  *	@return		HRESULT S_OK--�ɹ�  Other--����
  */
HRESULT DXGI_getOutputs(IDXGIAdapter* adapter, std::vector<IDXGIOutput*>& outputVec);

/**
  *	@name		DXGI_releaseAdaptersObjs
  * @brief		�ͷ�vector�е�����Adapter����
  *				��ÿ���������release��������vector.clear()���vector
  *	@param[in,out]	std::vector<IDXGIAdapter*>& adptVec ��������Adapter���Կ��������vector
  *	@return		HRESULT S_OK--�ɹ�  Other--����
  */
HRESULT DXGI_releaseAdaptersObjs(std::vector<IDXGIAdapter*>& adptVec);

/**
  *	@name		DXGI_releaseOutputObjs
  * @brief		�ͷ�vector�е�����Output����ʾ��������
  *				��ÿ���������release��������vector.clear()���vector
  *	@param[out]	std::vector<IDXGIOutput*>& outputVec ��������Output����ʾ���������vector
  *	@return		HRESULT S_OK--�ɹ�  Other--����
  */
HRESULT DXGI_releaseOutputObjs(std::vector<IDXGIOutput*>& outputVec);